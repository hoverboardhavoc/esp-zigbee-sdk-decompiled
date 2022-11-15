/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_extpanid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_extpanid(char *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_18 [5];
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  sVar1 = strlen(param_1);
  iVar2 = strcmp(param_1,"get");
  if (iVar2 != 0) {
    if (((sVar1 & 0xff) == 0x10) ||
       ((((sVar1 & 0xff) == 0x12 && (*param_1 == '0')) && (param_1[1] == 'x')))) {
      iVar2 = parse_address(param_1,auStack_18,3);
      if (iVar2 == 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC12,uVar3,0x10000);
      }
      else {
        zb_set_extended_pan_id(auStack_18);
        uVar3 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC11,uVar3,0x10000,uStack_11,uStack_12,uStack_13);
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC13,uVar3,0x10000);
    }
    return;
  }
  zb_get_extended_pan_id(auStack_18);
  uVar3 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_LC10,uVar3,0x10000,uStack_11,uStack_12,uStack_13);
  return;
}

