/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_start(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC8,uVar2,0x10000,"cmd_zb_start",0x1a6);
    return;
  }
  if (((char *)*param_1 != (char *)0x0) && (iVar1 = strcmp((char *)*param_1,"help"), iVar1 == 0)) {
    uVar2 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_LC20,uVar2,0x10000);
    done_or_failed(0);
    return;
  }
  if (m_stack_is_started == '\0') {
    uVar2 = zb_get_bdb_primary_channel_set();
    zb_aib_tcpol_set_is_distributed_security(m_is_distributed);
    if (m_default_role == '\x01') {
      zb_set_network_router_role(uVar2);
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC21,uVar2,0x10000);
    }
    else if (m_default_role == '\x02') {
      zb_set_network_ed_role(uVar2);
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC23,uVar2,0x10000);
    }
    else {
      if (m_default_role != '\0') {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC24,uVar2,0x10000);
        return;
      }
      zb_set_network_coordinator_role(uVar2);
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC22,uVar2,0x10000);
    }
    if (((char *)*param_1 == (char *)0x0) || (iVar1 = strcmp((char *)*param_1,"auto"), iVar1 == 0))
    {
      iVar1 = zboss_start_no_autostart();
    }
    else {
      iVar1 = zboss_start();
    }
    if (iVar1 != 0) goto _L0;
  }
  else {
    iVar1 = zb_zdo_joined();
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC27,uVar2,0x10000);
      iVar1 = 0;
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC26,uVar2,0x10000);
      iVar1 = 0;
    }
  }
  m_stack_is_started = '\x01';
_L0:
  done_or_failed(iVar1);
  return;
}

