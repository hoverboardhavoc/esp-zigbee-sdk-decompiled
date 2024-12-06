/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_ota_upgrade.o -> zcl_ota_upgrade_srv_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ota_upgrade_srv_status_handler(undefined4 param_1)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uStack_34;
  undefined1 auStack_30 [2];
  undefined2 uStack_2e;
  undefined1 auStack_2c [12];
  int iStack_20;
  undefined2 uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  puVar2 = (uint *)zb_buf_get_tail_func(param_1,0x38);
  if (*puVar2 < 0x27) {
    return 0xffffffff;
  }
  memset(auStack_30,0,0x20);
  uStack_34 = (uint)(iVar1 == 0);
  auStack_30[0] = 0xff;
  if (iVar1 != 0) {
    auStack_30[0] = *(undefined1 *)(iVar1 + 4);
  }
  uStack_2e = 0x19;
  piVar3 = (int *)zb_buf_get_tail_func(param_1,0x38);
  iStack_20 = *piVar3 + -0x27;
  piVar3 = (int *)zb_buf_get_tail_func(param_1,0x38);
  iVar5 = *piVar3;
  if (iVar5 == 0x28) {
_L0:
    uStack_1c = *(undefined2 *)(iVar1 + 0x10);
    uStack_18 = *(uint *)(iVar1 + 0x12);
  }
  else {
    if (iVar5 != 0x29) {
      if (iVar5 != 0x27) goto _L0;
      goto _L0;
    }
    uStack_34 = (uint)*(byte *)(iVar1 + 0x14);
    uStack_1c = (undefined2)((uint)*(undefined4 *)(iVar1 + 0x14) >> 8);
    uStack_18 = *(int *)(iVar1 + 0x18) << 8 | (uint)*(byte *)(iVar1 + 0x17);
    uStack_14 = *(undefined4 *)(iVar1 + 0x10);
  }
  memcpy(auStack_2c,*(void **)(iVar1 + 0xc),9);
_L0:
  esp_zb_core_action_handler_schedule(5,&uStack_34);
  uVar4 = esp_err_to_zb_ret();
  return uVar4;
}

