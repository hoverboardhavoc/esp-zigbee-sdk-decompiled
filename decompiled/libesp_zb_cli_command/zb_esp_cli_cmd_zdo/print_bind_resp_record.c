/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> print_bind_resp_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void print_bind_resp_record(undefined4 param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uStack_4c;
  char acStack_48 [20];
  char acStack_34 [32];
  
  uVar2 = 0;
  for (bVar1 = 0; bVar1 < 8; bVar1 = bVar1 + 1) {
    sprintf(acStack_34 + uVar2,"%02x");
    uVar2 = uVar2 + 2 & 0xff;
  }
  if (*(char *)(param_2 + 0xb) == '\x01') {
    sprintf(acStack_48,"%4x");
    uStack_4c = 0x412f4e;
  }
  else if (*(char *)(param_2 + 0xb) == '\x03') {
    uVar2 = 0;
    for (bVar1 = 0; bVar1 < 8; bVar1 = bVar1 + 1) {
      sprintf(acStack_48 + uVar2,"%02x");
      uVar2 = uVar2 + 2 & 0xff;
    }
    sprintf((char *)&uStack_4c,"%3d");
  }
  else {
    builtin_strncpy(acStack_48,"N/A",4);
    uStack_4c = 0x412f4e;
  }
  uStack_4c = uStack_4c & 0xffffff;
  uVar3 = esp_log_timestamp();
  esp_log_write(3,&_LC3,&_LC31,uVar3,&_LC3,param_1,acStack_34,*(undefined1 *)(param_2 + 8));
  return;
}

