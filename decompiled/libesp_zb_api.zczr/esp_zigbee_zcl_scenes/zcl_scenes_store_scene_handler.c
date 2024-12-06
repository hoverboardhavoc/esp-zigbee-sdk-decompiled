/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_store_scene_handler
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
      if ((&DAT_000115aa)[iVar5 * 6] == -1) {
        (&DAT_000115aa)[iVar5 * 6] = uVar3;
        (&DAT_000115ae)[iVar5 * 0xc] = uVar2;
        (&DAT_000115ac)[iVar5 * 6] = 0;
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
  iVar7 = esp_zb_has_core_action_handler();
  iVar5 = iVar6;
  if (iVar7 != 0) {
    esp_zb_core_action_handler_schedule(1,&local_30);
    iVar5 = esp_err_to_zb_ret();
    if ((iVar5 == 0) && (iVar5 = iVar6, iVar6 != -0x1b)) {
      iVar5 = 0;
    }
  }
  return iVar5;
}

