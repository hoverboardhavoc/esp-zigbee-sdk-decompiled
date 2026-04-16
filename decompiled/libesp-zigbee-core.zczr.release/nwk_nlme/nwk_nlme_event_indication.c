/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_nlme_event_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_nlme_event_indication(nwk_nlme_event_ind_t *ind)

{
  nwk_network_status_t status;
  ezb_shortaddr_t eVar1;
  char *pcVar2;
  
  if (ind->event != '\0') {
    if (ind->event == '\x01') {
      log_write(3,"nwk_nlme.c","Permit Joining: duration %d",(ind->field_1).network_status.status);
      return;
    }
    ind = (nwk_nlme_event_ind_t *)__assert_func(0,0,0,0);
  }
  status = (ind->field_1).network_status.status;
  eVar1 = (ind->field_1).network_status.network_addr;
  pcVar2 = nwk_network_status_to_str(status);
  log_write(3,"nwk_nlme.c","NWK Status Indication: %s (0x%02x), addr 0x%04x",pcVar2,status,eVar1);
  return;
}

