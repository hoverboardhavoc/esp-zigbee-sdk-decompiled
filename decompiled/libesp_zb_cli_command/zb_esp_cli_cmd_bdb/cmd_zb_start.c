/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_start(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (m_stack_is_started == '\0') {
    zb_get_bdb_primary_channel_set();
    if (m_default_role == '\0') {
      zb_set_network_coordinator_role();
      uVar1 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC5,uVar1,0x10000);
    }
    else {
      if (m_default_role != '\x01') {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC6,uVar1,0x10000);
        return;
      }
      zb_set_network_router_role();
      uVar1 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC4,uVar1,0x10000);
    }
    iVar2 = zboss_start_no_autostart();
    if (iVar2 == 0) {
_L0:
      m_stack_is_started = 1;
      uVar1 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC7,uVar1,0x10000);
      return;
    }
  }
  else {
    iVar2 = bdb_start_top_level_commissioning(2);
    if (iVar2 != 0) goto _L0;
  }
  uVar1 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC8,uVar1,0x10000);
  return;
}

