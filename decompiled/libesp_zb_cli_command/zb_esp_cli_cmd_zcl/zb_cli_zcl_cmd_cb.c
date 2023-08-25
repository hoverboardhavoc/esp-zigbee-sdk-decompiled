/*
 * Last changed at upstream commit 62f83e9155a8a668183e90087b29cd6791297d4c
 * https://github.com/espressif/esp-zigbee-sdk/commit/62f83e9155a8a668183e90087b29cd6791297d4c
 * Upstream date: 2023-08-25 15:56:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.1(b4845e06)
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
    if (*(int *)(DAT_000103bc + 0x34) != 0) {
      cmd_zb_attr(param_1 + -2,param_2 + 8);
    }
    if (*(int *)(DAT_000103c0 + 0x34) != 0) {
      cmd_zb_subscribe(param_1 + -2,param_2 + 8);
    }
    iVar1 = *(int *)(DAT_000103c4 + 0x34);
    if (iVar1 != 0) {
      cmd_zb_ping(param_1 + -2,param_2 + 8);
      iVar1 = 0;
    }
  }
  return iVar1;
}

