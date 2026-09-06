from pathlib import Path
import re, html
from PIL import Image, ImageDraw, ImageFont
root=Path('dactyl/keymaps/roger'); out=root/'layer-reference'; out.mkdir(exist_ok=True)
s=(root/'keymap.c').read_text()
config = (root.parents[1]/'config.h').read_text()
repeat_ms = int(re.search(r'^#define SQL_LINE_REPEAT_INTERVAL_MS\s+(\d+)', config, re.M).group(1))

blocks=re.findall(r'\[(_\w+)\] = LAYOUT_split_3x6_3\((.*?)\n\)',s,re.S)
layers={}
for name,body in blocks:
    body=re.sub(r'//[^\n]*','',body); tokens=[]; start=depth=0
    for i,c in enumerate(body):
        if c=='(': depth+=1
        elif c==')': depth-=1
        elif c==',' and depth==0: tokens.append(body[start:i].strip()); start=i+1
    tokens.append(body[start:].strip()); assert len(tokens)==42,(name,len(tokens)); layers[name]=tokens
labels={'SQL_REPEAT_DELETE_ROW':'Repeat delete row','KC_HOME':'Home','KC_END':'End','KC_UP':'Up','KC_DOWN':'Down','KC_LEFT':'Left','KC_RGHT':'Right','KC_PGUP':'Page Up','KC_PGDN':'Page Down','TRAINING_TOGGLE':'Training toggle','G(KC_R)':'Win+R', 'G(KC_L)':'Win+L', 'SQL_REPEAT_SINGLE':'Repeat quotes', 'SQL_REPEAT_DOUBLE':'Repeat dbl quotes', 'SQL_REPEAT_COMMA':'Repeat comma', 'GRVTI':'` | ~','QESC':'Q | Esc','PAT':'P | @','QTDQT':"\' | \"",'ASTPC':'* | %','EXCPI':'! | |','SCLCL':'; | :','SLBSL':'/ | \\', 'CMALT':', | <','DOTGT':'. | >','QSUDR':'? | _','LBDLR':'# | $','CTAMP':'^ | &','PLSMN':'+ | -','EQNEQ':'= | !=','ZDOT':'0 | .','LT(0,KC_9)':'( | ) + Left','LT(0,KC_0)':'[ | ] + Left','LT(0,KC_8)':'{ | } + Left','KC_SPC':'Space','KC_ENT':'Enter','QK_LLCK':'Layer lock','MO(_MOUS)':'Hold Mouse','MO(_SYM)':'Hold Symbols','MO(_PSS)':'Hold Secrets','MO(_FUNC)':'Hold Function','C(A(KC_DEL))':'Ctrl+Alt+Del','C(KC_Z)':'Undo','C(KC_C)':'Copy','C(KC_V)':'Paste','C(KC_X)':'Cut','C(KC_A)':'Select all','VDB':'Desktop left','VDF':'Desktop right','KC_LALT':'Hold Alt','KC_LCTL':'Hold Ctrl','KC_RCTL':'Hold Ctrl','KC_LSFT':'Hold Shift','KC_MUTE':'Mute','KC_VOLU':'Volume +','KC_VOLD':'Volume -','MS_BTN1':'Left click','MS_BTN2':'Right click','MS_UP':'Mouse up','MS_DOWN':'Mouse down','MS_LEFT':'Mouse left','MS_RGHT':'Mouse right','MS_WHLU':'Scroll up','MS_WHLD':'Scroll down','_______':'Transparent','XXXXXXX':'Unused'}
for mod,label in [('RALT','Alt'),('RCTL','Ctrl'),('RSFT','Shift'),('RGUI','Win')]: labels['OSM(MOD_'+mod+')']='OSM '+label
for n in range(1,37): labels['MY_'+str(n)]='Secret '+str(n)
# Read only the leading label comment; never parse or display secret values.
label_comment = []
with (root.parents[1]/'secrets.h').open(encoding='utf-8-sig') as label_file:
    first = label_file.readline()
    if first.strip() != '/* Secret label reference (labels only; no secret values).':
        raise ValueError('Missing leading secret label reference comment')
    for line in label_file:
        if '*/' in line:
            break
        label_comment.append(line)
    else:
        raise ValueError('Unterminated secret label reference comment')
for slot, display_label in re.findall(r'^\s*\*\s*(\d+):\s*(.+?)\s*$', ''.join(label_comment), re.M):
    if not 1 <= int(slot) <= 36:
        raise ValueError('Secret label slot must be between 1 and 36')
    labels['MY_'+str(int(slot))] = display_label

def label(k):
    if k in labels:return labels[k]
    if k.startswith('KC_KP_'):return 'Num '+k[6:]
    if k.startswith('KC_'):return k[3:]
    raise ValueError(k)
fontpath='C:/Windows/Fonts/segoeui.ttf'
def font(n):return ImageFont.truetype(fontpath,n)
meta=[('_QWERTY','Base','#2563eb','Default typing layer','Combos: D+F = Backspace; J+K = Enter; J+K+L = Tab; F+J = Leader.','X+C / C+V = desktop left / right. Shift + D+F = Delete.'),('_SYM','Symbols','#0891b2','Hold the inner right thumb key','Num labels are keypad digits. 5+6 = Backspace; Shift+5+6 = Delete.','Hold the left middle thumb from here to enter Function.'),('_MOUS','Mouse','#a87900','Hold the inner left thumb key; physical Z locks this layer','A / S / D / F = Undo / Copy / Cut / Paste. X = Alt; C = Ctrl; V = Shift.','Z locks Mouse; hold the right middle thumb for Function/navigation.'),('_FUNC','Function','#9333ea','From Symbols: left middle thumb. From Mouse: right middle thumb.','Far-left top = training. W / E / R / T = repeat delete row / comma / single / double quotes.',f'Repeats pause {repeat_ms} ms. D / F / G = Win+R / Ctrl+Alt+Delete / Win+L.'),('_PSS','Secrets','#dc2626','Hold both inner thumb layer keys: Symbols + Mouse','Descriptive labels only; no secret text is included.','After a secret types, layers clear. Release and press the layer keys again.')]
for name,title,color,entry,note,note2 in meta:
    im=Image.new('RGB',(1800,930),'#f6f8fc'); d=ImageDraw.Draw(im)
    d.rectangle((0,0,1800,12),fill=color);d.text((65,38),'DACTYL / '+title.upper(),font=font(44),fill='#152238')
    d.text((65,104),entry,font=font(24),fill='#475569')
    d.text((65,157),'LEFT HAND',font=font(17),fill=color);d.text((990,157),'RIGHT HAND',font=font(17),fill=color)
    for i,k in enumerate(layers[name]):
        if i<36:row=i//12; col=i%12; side=col//6;col%=6; x=65+side*920+col*125;y=200+row*112
        else:side=(i-36)//3;col=(i-36)%3;x=(440 if side==0 else 985)+col*125;y=556
        muted=k in ('XXXXXXX','_______');fill='#e9eef5' if muted else 'white'
        d.rounded_rectangle((x,y,x+116,y+96),radius=12,fill=fill,outline='#d1dae6' if muted else color,width=2)
        text=label(k); size=21
        while d.textbbox((0,0),text,font=font(size))[2]>106: size-=1
        d.text((x+58,y+39),text,anchor='mm',font=font(size),fill='#7c889a' if muted else '#17253b')
        tag='tap | hold' if ' | ' in text else ('tap to queue' if k.startswith('OSM') else '')
        if tag:d.text((x+58,y+72),tag,anchor='mm',font=font(12),fill='#64748b')
    d.text((65,700),note,font=font(23),fill='#24344d');d.text((65,741),note2,font=font(23),fill='#24344d')
    d.text((65,809),'Transparent = use the next active lower layer. Unused = no action.',font=font(20),fill='#64748b')
    d.text((65,845),'Schematic key positions, viewed from above. OSM = one-shot modifier; tap and release before the next key.',font=font(20),fill='#64748b')
    im.save(out/(name[1:].lower()+'.png'))
# Leader reference: validate every displayed sequence against the keymap.
leader_labels = {'sql_count_as': 'COUNT(*) as CntOf', 'sql_declare_int': 'DECLARE integer', 'sql_declare_str': 'DECLARE string', 'sql_declare_dttm': 'DECLARE date/time', 'sql_external_user_template': 'External user + data reader', 'sql_declare_columns_search': 'Search column metadata', 'sql_query_store': 'Query Store: top duration', 'sql_search_procs': 'Search stored procedure text', 'sql_inner_join': 'INNER JOIN', 'sql_left_outer_join': 'LEFT OUTER JOIN', 'sql_min_as': 'MIN() as MinOf', 'sql_max_as': 'MAX() as MaxOf', 'sql_row_number': 'ROW_NUMBER()', 'sql_select_template': 'SELECT * template', 'sql_count_select_template': 'SELECT COUNT template', 'sql_proc_template': 'Stored procedure template', 'sql_top_template': 'SELECT TOP (100) template', 'sql_transaction_template': 'Transaction template', 'sql_update_template': 'UPDATE template', 'sql_upsert_template': 'MERGE upsert template', 'sql_where_equals': 'WHERE equals', 'sql_where_between': 'WHERE BETWEEN', 'sql_where_in': 'WHERE IN (...)', 'sql_where_like': 'WHERE LIKE', 'sql_where_is_null': 'WHERE IS NULL'}
leader_actions = []
for keys, action in re.findall(r'leader_sequence_\w+\(([^)]*)\)\)\s*\{\s*run_leader_action\((\w+),', s):
    sequence = ' '.join(re.findall(r'KC_([A-Z])', keys))
    leader_actions.append((sequence, leader_labels[action]))
assert leader_actions, 'No leader actions found'
leader_actions.sort(key=lambda item: tuple(item[0].split()))
im = Image.new('RGB', (1800,930), '#f6f8fc'); d = ImageDraw.Draw(im)
d.rectangle((0,0,1800,12), fill='#2563eb')
d.text((65,38), 'DACTYL / LEADER KEYS', font=font(44), fill='#152238')
d.text((65,105), 'Press F+J together, release, then tap the sequence below.', font=font(26), fill='#475569')
d.text((65,147), 'Sequences are tapped in order after releasing the leader combo; repeated letters are separate taps.', font=font(22), fill='#475569')
for i,(seq,action) in enumerate(leader_actions):
    rows_per_col = (len(leader_actions) + 1) // 2
    col = i // rows_per_col; row = i % rows_per_col
    x=65+col*860; y=215+row*43
    d.rounded_rectangle((x,y,x+810,y+39), radius=7, fill='white' if row%2==0 else '#e9eef5')
    d.text((x+14,y+6),seq,font=font(21),fill='#2563eb')
    d.text((x+185,y+6),action,font=font(21),fill='#17253b')
d.text((65,813), 'Finish the sequence within the configured 750 ms leader window.', font=font(23), fill='#24344d')
d.text((65,853), 'SQL macros clear modifiers while typing; held modifiers are restored afterward.', font=font(21), fill='#64748b')
im.save(out/'leader.png')

page='''<!doctype html><html><head><meta charset="utf-8"><title>Dactyl layer reference</title><style>body{font-family:Segoe UI,sans-serif;margin:24px;background:#eef2f7}section{background:white;max-width:1100px;margin:20px auto;break-after:page}img{width:100%;display:block}@page{size:landscape;margin:8mm}@media print{body{margin:0;background:white}section{margin:0;max-width:none}section:last-child{break-after:auto}}</style></head><body>'''
for name,*_ in meta: page+='<section><img alt="'+html.escape(name)+' layer" src="'+name[1:].lower()+'.png"></section>'
page += '<section><img alt="Leader key sequences" src="leader.png"></section>'
(out/'print-reference.html').write_text(page+'</body></html>')
print('Created six 1800x930 PNG reference images and printable HTML in '+str(out.resolve()))
