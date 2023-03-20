/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
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
  if (iVar2 != 0) {
    if (((sVar1 & 0xff) == 4) ||
       ((((sVar1 & 0xff) == 6 && (*param_1 == '0')) && (param_1[1] == 'x')))) {
      iVar2 = parse_hex_u16(param_1,auStack_12);
      if (iVar2 == 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC16,uVar3,0x10000);
      }
      else {
        _DAT_0001612e = auStack_12[0];
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
  uVar3 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_L0,uVar3,0x10000,_DAT_0001612e);
  return;
}

