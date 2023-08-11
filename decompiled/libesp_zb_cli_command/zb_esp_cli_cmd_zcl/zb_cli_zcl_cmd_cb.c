/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl.o -> zb_cli_zcl_cmd_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_cli_zcl_cmd_cb(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  arg_parse(&zcl_args);
  if (param_1 < 3) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC4,uVar2,0x10000);
    iVar1 = 1;
  }
  else {
    if (*(int *)(zcl_args + 0x34) != 0) {
      cmd_zb_general_cmd(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00010310 + 0x34) != 0) {
      cmd_zb_attr(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_00010314 + 0x34) != 0) {
      cmd_zb_subscribe(param_1 + -2,param_2 + 8);
    }
    iVar1 = *(int *)(DAT_00010318 + 0x34);
    if (iVar1 != 0) {
      cmd_zb_ping(param_1 + -2,param_2 + 8);
      iVar1 = 0;
    }
  }
  return iVar1;
}

