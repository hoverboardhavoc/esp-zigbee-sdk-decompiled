/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cmd_zb_panid(char *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 auStack_12 [3];
  
  sVar1 = strlen(param_1);
  iVar2 = strcmp(param_1,"get");
  if (iVar2 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_LC14,uVar3,0x10000,_DAT_000152d6);
  }
  else if (((sVar1 & 0xff) == 4) ||
          ((((sVar1 & 0xff) == 6 && (*param_1 == '0')) && (param_1[1] == 'x')))) {
    sVar1 = strlen(param_1);
    iVar2 = parse_hex_str(param_1,sVar1 & 0xff,auStack_12,2,1);
    if (iVar2 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC16,uVar3,0x10000);
    }
    else {
      _DAT_000152d6 = auStack_12[0];
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC15,uVar3,0x10000,auStack_12[0]);
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC13,uVar3,0x10000);
  }
  return;
}

