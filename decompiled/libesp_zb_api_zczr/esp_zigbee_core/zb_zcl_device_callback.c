/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_device_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_device_callback(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  code *pcVar4;
  int *piVar5;
  
  piVar5 = &s_device_cb_table;
  iVar1 = 0;
  do {
    piVar2 = (int *)zb_buf_get_tail_func(param_1,0x38);
    if (*piVar2 == *piVar5) {
      pcVar4 = (code *)(&PTR_zcl_basic_reset_factory_reset_cb_handler_00015920)[iVar1 * 2];
      iVar1 = zb_buf_get_tail_func(param_1,0x38);
      uVar3 = (*pcVar4)(param_1);
      *(undefined4 *)(iVar1 + 8) = uVar3;
      return;
    }
    iVar1 = iVar1 + 1;
    piVar5 = piVar5 + 2;
  } while (iVar1 != 0x24);
  if ((zcl_device_id_cb == (code *)0x0) || (iVar1 = (*zcl_device_id_cb)(param_1), iVar1 == 0)) {
    iVar1 = zb_buf_get_tail_func(param_1,0x38);
    *(undefined4 *)(iVar1 + 8) = 0xffffffff;
  }
  return;
}

