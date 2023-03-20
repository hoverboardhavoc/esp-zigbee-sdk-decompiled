/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_ping.o -> ping_cli_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ping_cli_evt_handler(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 extraout_a1;
  undefined4 extraout_a1_00;
  
  if (param_1 == 1) {
    uVar1 = esp_log_timestamp();
    uVar2 = __udivdi3(param_2,param_3,1000,0);
    esp_log_write(1,&_LC0,&_LC1,uVar1,&_LC0,uVar2,extraout_a1);
  }
  else if (param_1 == 2) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,&_LC0,&_LC4,uVar1,&_LC0);
  }
  else if (param_1 == 0) {
    uVar1 = esp_log_timestamp();
    uVar2 = __udivdi3(param_2,param_3,1000,0);
    esp_log_write(3,&_LC0,&_LC2,uVar1,&_LC0,uVar2,extraout_a1_00);
    uVar1 = esp_log_timestamp();
    esp_log_write(3,&_LC0,&_LC3,uVar1,&_LC0);
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,&_LC0,&_LC5,uVar1,&_LC0,param_1);
  }
  return;
}

