/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_install_code
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_install_code(char *param_1,char *param_2,int param_3)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined1 auStack_2c [5];
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  
  if (param_2 != (char *)0x0) {
    iVar1 = strcmp(param_1,"set");
    if (iVar1 == 0) {
      sVar2 = strlen(param_2);
      iVar1 = parse_hex_str(param_2,sVar2 & 0xff,&uStack_24,0x12,0);
      if (iVar1 == 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC71,uVar3,0x10000);
        return;
      }
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC72,uVar3,0x10000,uStack_24,uStack_23,uStack_22);
      iVar1 = zb_secur_ic_set(3,&uStack_24);
      if (iVar1 != 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC73,uVar3,0x10000);
        return;
      }
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC7,uVar3,0x10000);
      return;
    }
    if ((param_3 != 0) && (iVar1 = strcmp(param_1,"add"), iVar1 == 0)) {
      if (m_stack_is_started == '\0') {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC75,uVar3,0x10000);
        return;
      }
      sVar2 = strlen(param_2);
      iVar1 = parse_hex_str(param_2,sVar2 & 0xff,&uStack_24,0x12,0);
      if (iVar1 == 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC71,uVar3,0x10000);
        return;
      }
      iVar1 = parse_address(param_3,auStack_2c,3);
      if (iVar1 == 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC76,uVar3,0x10000);
        return;
      }
      if (1 < m_default_role) {
        uVar3 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC78,uVar3,0x10000);
        uVar3 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC8,uVar3,0x10000);
        return;
      }
      zb_secur_ic_add(auStack_2c,3,&uStack_24,0);
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC72,uVar3,0x10000,uStack_24,uStack_23,uStack_22);
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC77,uVar3,0x10000,uStack_25,uStack_26,uStack_27);
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC7,uVar3,0x10000);
      return;
    }
  }
  if ((param_2 == (char *)0x0) || (iVar1 = strcmp(param_1,"policy"), iVar1 != 0)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC82,uVar3,0x10000);
  }
  else {
    iVar1 = strcmp(param_2,"enable");
    if (iVar1 == 0) {
      zb_set_installcode_policy(1);
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC7,uVar3,0x10000);
    }
    else {
      iVar1 = strcmp(param_2,"disable");
      if (iVar1 == 0) {
        zb_set_installcode_policy();
        uVar3 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC7,uVar3,0x10000);
      }
      else {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC82,uVar3,0x10000);
      }
    }
  }
  return;
}

