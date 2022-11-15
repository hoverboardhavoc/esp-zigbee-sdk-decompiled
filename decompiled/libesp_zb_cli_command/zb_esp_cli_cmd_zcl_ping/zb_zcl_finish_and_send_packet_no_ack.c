/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_ping.o -> zb_zcl_finish_and_send_packet_no_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_finish_and_send_packet_no_ack
               (undefined4 param_1,undefined2 *param_2,int param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 auStack_32 [7];
  
  uVar1 = zb_buf_get_ptr_off_func();
  uVar1 = zb_buf_alloc_left_func(param_1,uVar1);
  if (param_3 == 2) {
    auStack_32[0] = *param_2;
  }
  else if (param_3 == 3) {
    iVar2 = zb_address_short_by_ieee(param_2);
    auStack_32[0] = (undefined2)iVar2;
    if (iVar2 == 0xffff) {
      zb_buf_free_func(param_1);
      return;
    }
    param_3 = 2;
  }
  else {
    if (param_3 != 0) {
      zb_buf_free_func(param_1);
      return;
    }
    auStack_32[0] = 0xffff;
  }
  zb_zcl_finish_and_send_packet_new
            (param_1,uVar1,auStack_32,param_3,param_4,param_5,param_6,param_7);
  return;
}

