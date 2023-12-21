/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
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
      esp_log_write(3,0x10000,&_LC2,uVar1,0x10000);
    }
    else {
      if (m_default_role != '\x01') {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC3,uVar1,0x10000);
        return;
      }
      zb_set_network_router_role();
      uVar1 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC1,uVar1,0x10000);
    }
    iVar2 = zboss_start_no_autostart();
    if (iVar2 == 0) {
_L0:
      m_stack_is_started = 1;
      uVar1 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC4,uVar1,0x10000);
      return;
    }
  }
  else {
    iVar2 = bdb_start_top_level_commissioning(2);
    if (iVar2 != 0) goto _L0;
  }
  uVar1 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC5,uVar1,0x10000);
  return;
}

