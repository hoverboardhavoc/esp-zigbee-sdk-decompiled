/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> zcl_scenes_recall_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_scenes_recall_scene(int param_1,uint param_2,undefined1 param_3,uint param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint extraout_a1;
  undefined1 auStack_4c [8];
  int iStack_44;
  undefined2 uStack_40;
  undefined1 uStack_3e;
  undefined2 uStack_3c;
  undefined4 uStack_38;
  byte bStack_34;
  
  if (param_1 != 0) goto _L0;
  do {
    param_4 = 0;
    param_3 = 0;
    param_1 = __assert_func(0,0);
    param_2 = extraout_a1;
_L0:
    if (0xfff7 < param_2) {
      return 0x87;
    }
    uVar1 = *(undefined1 *)(param_1 + 0x15);
    iVar2 = scene_table_find_entry(uVar1);
    if (iVar2 == 0) {
      return 0x8b;
    }
    if (param_4 == 0xffff) {
      param_4 = (uint)*(ushort *)(iVar2 + 6);
    }
    iVar3 = scenes_srv_get_attr_desc(uVar1,1);
    iVar4 = scenes_srv_get_attr_desc(uVar1,2);
    iVar5 = scenes_srv_get_attr_desc(uVar1,3);
  } while (((iVar3 == 0) || (iVar4 == 0)) || (iVar5 == 0));
  **(undefined1 **)(iVar3 + 8) = param_3;
  **(undefined2 **)(iVar4 + 8) = (short)param_2;
  **(undefined1 **)(iVar5 + 8) = 0;
  memset(auStack_4c,0,0x1c);
  uVar6 = zcl_packet_to_message(auStack_4c,param_1);
  if (uVar6 == 0) {
    uStack_40 = *(undefined2 *)(iVar2 + 2);
    uStack_3e = *(undefined1 *)(iVar2 + 4);
    uStack_3c = (undefined2)param_4;
    uStack_38 = *(undefined4 *)(iVar2 + 0x1c);
    bStack_34 = 0xfe;
    iStack_44 = param_1;
    zcl_core_action_schedule(0x16,auStack_4c);
    uVar6 = (uint)bStack_34;
    if ((uVar6 == 0xfe) || (uVar6 == 0)) {
      uVar6 = 0;
      **(undefined1 **)(iVar5 + 8) = 1;
    }
  }
  return uVar6;
}

