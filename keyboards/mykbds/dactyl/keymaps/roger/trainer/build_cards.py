from pathlib import Path
import runpy, json, os
root=Path(__file__).resolve().parents[1]
workspace=root.parents[2]
os.chdir(workspace)
data=runpy.run_path(str(root/'generate_layer_reference.py'))
positions=['outer','Q','W','E','R','T','Y','U','I','O','P','outer', 'outer','A','S','D','F','G','H','J','K','L','semicolon','outer', 'outer','Z','X','C','V','B','N','M','comma','period','outer','outer','left outer thumb','left middle thumb','left inner thumb','right inner thumb','right middle thumb','right outer thumb']
pairs={'GRVTI':('`','~'),'PAT':('p','@'),'QTDQT':("'",'"'),'ASTPC':('*','%'),'EXCPI':('!','|'),'SCLCL':(';',':'),'SLBSL':('/','\\'),'CMALT':(',','<'),'DOTGT':('.','>'),'QSUDR':('?','_'),'LBDLR':('#','$'),'CTAMP':('^','&'),'PLSMN':('+','-'),'EQNEQ':('=','!='),'ZDOT':('0','.'),'LT(0,KC_9)':('(',')'),'LT(0,KC_0)':('[',']'),'LT(0,KC_8)':('{','}')}
cards={'symbols':[],'mouse':[],'secrets':[]};seen=set()
for layer in ('_QWERTY','_SYM'):
 for i,key in enumerate(data['layers'][layer]):
  if key not in pairs: continue
  for action,value in zip(('Tap','Hold'),pairs[key]):
   if value.isalnum() or value in seen or len(value)!=1:continue
   seen.add(value)
   hint=('Base: ' if layer=='_QWERTY' else 'Hold Symbols (right inner thumb): ')+action+' '+positions[i]+f' (row {i//12+1}, '+('left' if i%12<6 else 'right')+' half).'
   cards['symbols'].append({'id':'symbol'+value,'label':value,'value':value,'hint':hint})
mouse={'MS_BTN1':('Left click','click',0),'MS_BTN2':('Right click','click',2),'MS_UP':('Move up','move','up'),'MS_DOWN':('Move down','move','down'),'MS_LEFT':('Move left','move','left'),'MS_RGHT':('Move right','move','right'),'MS_WHLU':('Scroll up','wheel',-1),'MS_WHLD':('Scroll down','wheel',1)}
for i,key in enumerate(data['layers']['_MOUS']):
 if key in mouse:
  label,kind,value=mouse[key];cards['mouse'].append({'id':key,'label':label,'kind':kind,'value':value,'hint':'Hold Mouse (left inner thumb), then '+positions[i]+f' (row {i//12+1}, right half).'})
# Physical Q-P, A-L, and Z-M positions are excluded from secret practice.
letter_positions = set(range(1,11)) | set(range(13,22)) | set(range(25,32))
for i,key in enumerate(data['layers']['_PSS']):
 if i in letter_positions:continue
 if not key.startswith('MY_'):continue
 label=data['labels'][key]
 if label.strip().lower()=='unused':continue
 cards['secrets'].append({'id':key,'label':label,'value':int(key[3:]),'hint':'Hold both inner thumb layer keys (either order); '+positions[i]+f' (row {i//12+1}, '+('left' if i%12<6 else 'right')+' half). Release layer keys before the next answer.'})
cards['leaders'] = [{'id':'leader'+seq.replace(' ',''), 'label':label, 'value':seq.replace(' ',''), 'hint':'Press F+J together, release, then tap '+seq+'. Training LED must be orange.'} for seq,label in data['leader_actions']]
(root/'trainer/cards.js').write_text('const CARDS = '+json.dumps(cards)+';',encoding='utf-8')
print({key:len(value) for key,value in cards.items()})
