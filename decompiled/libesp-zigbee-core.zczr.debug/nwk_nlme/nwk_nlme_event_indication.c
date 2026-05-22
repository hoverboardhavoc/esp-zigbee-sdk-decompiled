/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  byte *pbVar5;
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
  pbVar4 = (byte *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x65,
                                 "nwk_nlme_event_indication",&_LC18);
  bVar1 = *pbVar4;
  pnStack_18 = ind;
  pcStack_14 = pcVar2;
  if (bVar1 == 0xd) {
    nwk_address_conflict_resolve(*(undefined2 *)(pbVar4 + 1));
    return;
  }
  if (bVar1 < 0xe) {
    pbVar5 = pbVar4;
    if (bVar1 != 0xb) {
      if (bVar1 < 0xc) {
        if (bVar1 < 3) {
          nwk_route_table_remove_by_dst(*(undefined2 *)(pbVar4 + 1));
          return;
        }
        if (bVar1 == 9) goto _L0;
      }
      else if (bVar1 == 0xc) {
        nwk_concentrator_discovery();
        goto _L0;
      }
      goto _L0;
    }
  }
  else {
    if (bVar1 == 0x13) {
      return;
    }
    if (bVar1 < 0x14) {
      if ((byte)(bVar1 - 0xf) < 2) {
        ds_save_common_data();
        goto _L0;
      }
    }
    else if (bVar1 == 0x14) goto _L0;
_L0:
    pbVar5 = (byte *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0xb8,
                                   "nwk_handle_network_status_local",&_LC18);
  }
  nwk_route_record_table_remove_by_dst(CONCAT11(pbVar4[2],pbVar5[1]));
_L0:
  anStack_28[0]._0_4_ = (uint)*pbVar4 << 0x10;
  anStack_28[0].field_1._4_2_ = 0;
  anStack_28[0].field_1._2_2_ = *(ushort *)(pbVar4 + 1);
  nwk_nlme_event_indication(anStack_28);
  return;
}

