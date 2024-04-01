/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
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
        esp_log_write(1,0x10000,&_LC50,uVar3,0x10000);
      }
      else {
        _DAT_00015342 = auStack_12[0];
        uVar3 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC49,uVar3,0x10000,auStack_12[0]);
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC47,uVar3,0x10000);
    }
    return;
  }
  uVar3 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_L0,uVar3,0x10000,_DAT_00015342);
  return;
}

