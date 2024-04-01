/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_store_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_store_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 local_30;
  undefined1 uStack_2c;
  undefined2 uStack_2a;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined2 uStack_24;
  undefined1 uStack_22;
  
  iVar5 = zb_buf_get_tail_func(0x38);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  puVar4 = *(undefined2 **)(iVar6 + 0x10);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  iVar7 = *(int *)(iVar6 + 0xc);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  uStack_2c = *(undefined1 *)(iVar5 + 4);
  uVar1 = *(undefined1 *)(iVar7 + 0xc);
  local_30 = 0;
  uStack_2a = 5;
  uStack_28 = *(undefined1 *)(iVar7 + 0x13);
  puVar8 = *(undefined1 **)(iVar6 + 0x14);
  uStack_27 = *(undefined1 *)(iVar7 + 0x14);
  uStack_26 = *(undefined1 *)(iVar7 + 0x16);
  uStack_24 = *puVar4;
  uStack_22 = *(undefined1 *)(puVar4 + 1);
  iVar5 = esp_zb_zcl_scenes_group_check(uVar1);
  *puVar8 = (char)iVar5;
  if (iVar5 == 0) {
    uVar3 = *puVar4;
    uVar2 = *(undefined1 *)(puVar4 + 1);
    iVar5 = device_scenes_get_free_entry(uVar1,uVar3,uVar2);
    if (iVar5 != 0xff) {
      iVar6 = -0x1b;
      if ((&DAT_00015ba2)[iVar5 * 6] == -1) {
        (&DAT_00015ba2)[iVar5 * 6] = uVar3;
        (&DAT_00015ba6)[iVar5 * 0xc] = uVar2;
        (&DAT_00015ba4)[iVar5 * 6] = 0;
        iVar6 = 0;
      }
      *puVar8 = 0;
      goto _L0;
    }
    *puVar8 = 0x89;
    local_30 = 1;
  }
  iVar6 = 0;
_L0:
  iVar5 = iVar6;
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(1,&local_30);
    iVar5 = esp_err_to_zb_ret();
    if ((iVar5 == 0) && (iVar6 == -0x1b)) {
      iVar5 = -0x1b;
    }
  }
  return iVar5;
}

