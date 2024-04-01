/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_recall_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_recall_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_38;
  undefined1 uStack_34;
  undefined2 uStack_32;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined2 uStack_28;
  undefined4 uStack_24;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined2 **)(iVar5 + 0x10);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  iVar6 = *(int *)(iVar5 + 0xc);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  uStack_34 = *(undefined1 *)(iVar4 + 4);
  uVar1 = *(undefined1 *)(iVar6 + 0xc);
  uStack_38 = 0;
  uStack_32 = 5;
  uStack_30 = *(undefined1 *)(iVar6 + 0x13);
  puVar3 = *(undefined1 **)(iVar5 + 0x14);
  uStack_2f = *(undefined1 *)(iVar6 + 0x14);
  uStack_2e = *(undefined1 *)(iVar6 + 0x16);
  uStack_2c = *puVar2;
  uStack_2a = *(undefined1 *)(puVar2 + 1);
  uStack_28 = *(undefined2 *)((int)puVar2 + 3);
  uStack_24 = 0;
  iVar4 = esp_zb_zcl_scenes_group_check(uVar1);
  *puVar3 = (char)iVar4;
  if (iVar4 == 0) {
    iVar4 = device_scenes_get_free_entry(uVar1,*puVar2,*(undefined1 *)(puVar2 + 1));
    if ((iVar4 == 0xff) || ((&DAT_00015ba2)[iVar4 * 6] == -1)) {
      *puVar3 = 0x8b;
      uStack_38 = 0x8b;
    }
    else {
      uStack_24 = (&DAT_00015ba8)[iVar4 * 3];
      *puVar3 = 0;
    }
  }
  if (zb_core_action_cb == (code *)0x0) {
    return 0;
  }
  iVar4 = (*zb_core_action_cb)(2,&uStack_38);
  if (iVar4 == 0x105) {
    iVar5 = -0x1c;
  }
  else if (iVar4 < 0x106) {
    iVar5 = -0x16;
    if ((iVar4 != 0x101) && (iVar5 = -6, iVar4 != 0x104)) {
      return -(uint)(iVar4 != 0);
    }
  }
  else {
    iVar5 = -0x1e;
    if ((iVar4 != 0x107) && (iVar5 = -2, iVar4 != 0x10c)) {
      return -1;
    }
  }
  return iVar5;
}

