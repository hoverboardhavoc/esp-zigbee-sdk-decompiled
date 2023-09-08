/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
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
        _DAT_00016136 = auStack_12[0];
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
  esp_log_write(3,0x10000,&_L0,uVar3,0x10000,_DAT_00016136);
  return;
}

