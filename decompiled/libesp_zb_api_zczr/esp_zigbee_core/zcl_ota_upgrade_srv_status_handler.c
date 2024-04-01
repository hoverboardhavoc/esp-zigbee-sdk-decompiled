/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_ota_upgrade_srv_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_ota_upgrade_srv_status_handler(undefined4 param_1)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
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
  if (*puVar2 < 0x25) {
    return -1;
  }
  memset(auStack_30,0,0x20);
  uStack_34 = (uint)(iVar1 == 0);
  auStack_30[0] = 0xff;
  if (iVar1 != 0) {
    auStack_30[0] = *(undefined1 *)(iVar1 + 4);
  }
  uStack_2e = 0x19;
  piVar3 = (int *)zb_buf_get_tail_func(param_1,0x38);
  iStack_20 = *piVar3 + -0x25;
  piVar3 = (int *)zb_buf_get_tail_func(param_1,0x38);
  iVar4 = *piVar3;
  if (iVar4 == 0x26) {
_L0:
    uStack_1c = *(undefined2 *)(iVar1 + 0x10);
    uStack_18 = *(uint *)(iVar1 + 0x12);
  }
  else {
    if (iVar4 != 0x27) {
      if (iVar4 != 0x25) goto _L0;
      goto _L0;
    }
    uStack_34 = (uint)*(byte *)(iVar1 + 0x14);
    uStack_1c = (undefined2)((uint)*(undefined4 *)(iVar1 + 0x14) >> 8);
    uStack_18 = *(int *)(iVar1 + 0x18) << 8 | (uint)*(byte *)(iVar1 + 0x17);
    uStack_14 = *(undefined4 *)(iVar1 + 0x10);
  }
  memcpy(auStack_2c,*(void **)(iVar1 + 0xc),9);
_L0:
  if (zb_core_action_cb == (code *)0x0) {
    return 0;
  }
  iVar1 = (*zb_core_action_cb)(5,&uStack_34);
  if (iVar1 == 0x105) {
    iVar4 = -0x1c;
  }
  else if (iVar1 < 0x106) {
    iVar4 = -0x16;
    if ((iVar1 != 0x101) && (iVar4 = -6, iVar1 != 0x104)) {
      return -(uint)(iVar1 != 0);
    }
  }
  else {
    iVar4 = -0x1e;
    if ((iVar1 != 0x107) && (iVar4 = -2, iVar1 != 0x10c)) {
      return -1;
    }
  }
  return iVar4;
}

