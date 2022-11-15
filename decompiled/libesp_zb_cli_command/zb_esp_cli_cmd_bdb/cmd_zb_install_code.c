/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
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
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  
  if ((param_2 == (char *)0x0) || (iVar1 = strcmp(param_1,"set"), iVar1 != 0)) {
    if (((param_2 == (char *)0x0) || (param_3 == 0)) || (iVar1 = strcmp(param_1,"add"), iVar1 != 0))
    {
      if ((param_2 == (char *)0x0) || (iVar1 = strcmp(param_1,"policy"), iVar1 != 0)) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC37,uVar3,0x10000);
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
            esp_log_write(1,0x10000,&_LC37,uVar3,0x10000);
          }
        }
      }
    }
    else if (m_stack_is_started == '\0') {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC31,uVar3,0x10000);
    }
    else {
      sVar2 = strlen(param_2);
      iVar1 = parse_hex_str(param_2,sVar2 & 0xff,&uStack_24,0x12,0);
      if (iVar1 == 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC27,uVar3,0x10000);
      }
      else {
        iVar1 = parse_address(param_3,&uStack_2c,3);
        if (iVar1 == 0) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC32,uVar3,0x10000);
        }
        else {
          zb_secur_ic_add(&uStack_2c,3,&uStack_24,0);
          uVar3 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC28,uVar3,0x10000,uStack_24,uStack_23,uStack_22);
          uVar3 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC33,uVar3,0x10000,uStack_2c,uStack_2b,uStack_2a);
          uVar3 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC7,uVar3,0x10000);
        }
      }
    }
  }
  else {
    sVar2 = strlen(param_2);
    iVar1 = parse_hex_str(param_2,sVar2 & 0xff,&uStack_24,0x12,0);
    if (iVar1 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC27,uVar3,0x10000);
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC28,uVar3,0x10000,uStack_24,uStack_23,uStack_22);
      iVar1 = zb_secur_ic_set(3,&uStack_24);
      if (iVar1 == 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC7,uVar3,0x10000);
      }
      else {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC29,uVar3,0x10000);
      }
    }
  }
  return;
}

