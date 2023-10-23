/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> cmd_zb_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_attr(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *__s1;
  
  __s1 = (char *)*param_2;
  iVar1 = strcmp(__s1,"read");
  if (iVar1 == 0) {
    cmd_zb_read_attr(param_1 + -1,param_2 + 1);
  }
  else {
    iVar1 = strcmp(__s1,"write");
    if (iVar1 == 0) {
      cmd_zb_write_attr(param_1 + -1,param_2 + 1);
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_LC22,uVar2,&_LC0);
    }
  }
  return;
}

