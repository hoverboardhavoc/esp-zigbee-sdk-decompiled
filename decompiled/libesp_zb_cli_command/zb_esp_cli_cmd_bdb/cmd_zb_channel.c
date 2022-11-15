/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_channel(char *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  size_t sVar4;
  int iVar5;
  undefined4 uVar6;
  char acStack_84 [100];
  char *pcStack_20;
  char *pcStack_1c;
  uint auStack_18 [2];
  
  pcStack_20 = "Primary";
  pcStack_1c = "Secondary";
  sVar4 = strlen(param_1);
  iVar5 = strcmp(param_1,"get");
  if (iVar5 == 0) {
    auStack_18[0] = zb_get_bdb_primary_channel_set();
    auStack_18[1] = zb_get_bdb_secondary_channel_set();
    for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
      sprintf(acStack_84,"%s channel(s):");
      for (uVar1 = 0xb; (int)uVar1 < 0x1b; uVar1 = uVar1 + 1) {
        if ((1 << (uVar1 & 0x1f) & auStack_18[iVar5]) != 0) {
          sVar4 = strlen(acStack_84);
          sprintf(acStack_84 + sVar4," %d");
        }
      }
      uVar6 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC21,uVar6,0x10000,acStack_84);
    }
    return;
  }
  if (((sVar4 & 0xff) == 2) || ((*param_1 == '0' && (param_1[1] == 'x')))) {
    if (m_stack_is_started == '\0') {
      if ((sVar4 & 0xff) == 2) {
        uVar1 = strtol(param_1,(char **)0x0,10);
      }
      else if (*param_1 == '0') {
        if (param_1[1] == 'x') {
          uVar1 = strtol(param_1,(char **)0x0,0x10);
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
      if (uVar1 - 0xb < 0x10) {
        uVar2 = 1 << (uVar1 & 0x1f);
      }
      else if (((uVar1 & 0x7fff800) == 0) ||
              (uVar3 = uVar1 & 0xf80007ff, uVar2 = uVar1, uVar1 = uVar3, uVar3 != 0)) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC23,uVar6,0x10000);
        return;
      }
      uVar3 = zb_get_bdb_primary_channel_set();
      if (uVar3 != uVar2) {
        if (uVar1 == 0) {
          uVar6 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC25,uVar6,0x10000,uVar2);
        }
        else {
          uVar6 = esp_log_timestamp();
          esp_log_write(3,0x10000,&_LC24,uVar6,0x10000,uVar1);
        }
        zb_set_bdb_primary_channel_set(uVar2);
        zb_set_bdb_secondary_channel_set(uVar2);
        zb_set_channel_mask(uVar2);
      }
    }
    else {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC22,uVar6,0x10000);
    }
  }
  else {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC13,uVar6,0x10000);
  }
  return;
}

