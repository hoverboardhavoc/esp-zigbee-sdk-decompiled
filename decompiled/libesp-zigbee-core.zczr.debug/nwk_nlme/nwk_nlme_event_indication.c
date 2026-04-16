/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_nlme_event_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_nlme_event_indication(nwk_nlme_event_ind_t *ind)

{
  nwk_network_status_t status;
  byte bVar1;
  code *pcVar2;
  char *pcVar3;
  byte *pbVar4;
  nwk_nlme_event_ind_t anStack_28 [2];
  nwk_nlme_event_ind_t *pnStack_18;
  code *pcStack_14;
  
  if (ind->event == '\0') {
    status = (ind->field_1).network_status.status;
    pcVar3 = nwk_network_status_to_str(status);
    log_write(3,"nwk_nlme.c","NWK Status Indication: %s (0x%02x), addr 0x%04x",pcVar3,status,
              (ind->field_1).network_status.network_addr);
    return;
  }
  if (ind->event == '\x01') {
    log_write(3,"nwk_nlme.c","Permit Joining: duration %d",(ind->field_1).network_status.status);
    return;
  }
  pcVar2 = nwk_handle_network_status_local;
  pbVar4 = (byte *)__assert_func("//build/esp-zigbee/src/core/nwk/nwk_nlme.c",100,
                                 "nwk_nlme_event_indication",&_LC18);
  bVar1 = *pbVar4;
  pnStack_18 = ind;
  pcStack_14 = pcVar2;
  if (bVar1 != 0xc) {
    if (bVar1 < 0xd) {
      if (bVar1 == 9) goto _L0;
      if (bVar1 < 10) {
        if (bVar1 < 3) {
          nwk_route_table_remove_by_dst(*(undefined2 *)(pbVar4 + 1));
          return;
        }
      }
      else if (bVar1 == 0xb) {
        nwk_route_record_table_remove_by_dst(*(undefined2 *)(pbVar4 + 1));
        goto _L0;
      }
    }
    else {
      if (bVar1 == 0x13) {
        return;
      }
      if (bVar1 < 0x14) {
        if (bVar1 == 0xd) {
          nwk_address_conflict_resolve(*(undefined2 *)(pbVar4 + 1));
          return;
        }
        if ((0xc < bVar1) && ((byte)(bVar1 - 0xf) < 2)) goto _L0;
      }
      else if (bVar1 == 0x14) goto _L0;
    }
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_nlme.c",0xb2,
                  "nwk_handle_network_status_local",&_LC18);
  }
  nwk_concentrator_discovery();
_L0:
  anStack_28[0]._0_4_ = (uint)*pbVar4 << 0x10;
  anStack_28[0].field_1._4_2_ = 0;
  anStack_28[0].field_1._2_2_ = *(ushort *)(pbVar4 + 1);
  nwk_nlme_event_indication(anStack_28);
  return;
}

