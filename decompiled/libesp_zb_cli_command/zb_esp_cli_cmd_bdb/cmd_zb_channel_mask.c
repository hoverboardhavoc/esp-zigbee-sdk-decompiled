/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_channel_mask
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_channel_mask(int param_1,undefined4 *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lStack_18;
  int iStack_14;
  
  lStack_18 = 0;
  iStack_14 = 0;
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC14,uVar3,0x10000,"cmd_zb_channel_mask",0x296);
    return;
  }
  pcVar1 = (char *)*param_2;
  iVar2 = strcmp(pcVar1,"help");
  if (iVar2 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_L0,uVar3,0x10000);
    done_or_failed(0);
    return;
  }
  iVar2 = strcmp(pcVar1,"get");
  if (iVar2 == 0) {
    uVar3 = zb_get_bdb_primary_channel_set();
    uVar4 = zb_get_bdb_secondary_channel_set();
    uVar5 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_LC67,uVar5,0x10000,uVar3,uVar4);
    done_or_failed(0);
    return;
  }
  if (m_stack_is_started != '\0') {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC19,uVar3,0x10000);
    done_or_failed(0);
    return;
  }
  if ((((pcVar1 == (char *)0x0) || (*pcVar1 != '0')) || (pcVar1[1] != 'x')) ||
     (lStack_18 = strtol(pcVar1,(char **)0x0,0x10), lStack_18 - 0x800U < 0x7fff001)) {
    pcVar1 = (char *)param_2[1];
    if (pcVar1 == (char *)0x0) {
      iVar2 = 0;
    }
    else if (*pcVar1 == '0') {
      if (pcVar1[1] == 'x') {
        iStack_14 = strtol(pcVar1,(char **)0x0,0x10);
        if (0x7fff000 < iStack_14 - 0x800U) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC63,uVar3,0x10000);
          goto _L0;
        }
        iVar2 = 0;
      }
      else {
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC63,uVar3,0x10000);
    iVar2 = -1;
  }
  if (iVar2 == 0) {
    if (lStack_18 != 0) {
      zb_set_bdb_primary_channel_set(lStack_18);
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC68,uVar3,0x10000,lStack_18);
    }
    if (iStack_14 != 0) {
      zb_set_bdb_secondary_channel_set(iStack_14);
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC69,uVar3,0x10000,iStack_14);
    }
    uVar3 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_LC7,uVar3,0x10000);
    return;
  }
_L0:
  uVar3 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_LC8,uVar3,0x10000);
  return;
}

