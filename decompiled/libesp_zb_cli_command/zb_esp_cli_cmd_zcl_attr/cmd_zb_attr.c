/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
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
      esp_log_write(1,&_L0,&_LC22,uVar2,&_L0);
    }
  }
  return;
}

