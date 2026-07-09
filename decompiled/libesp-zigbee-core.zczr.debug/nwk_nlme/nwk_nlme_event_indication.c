/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_nlme_event_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_nlme_event_indication(char *param_1)

{
  char cVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 uVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iStack_28;
  uint uStack_24;
  char *pcStack_18;
  code *pcStack_14;
  
  if (*param_1 == '\0') {
    cVar1 = param_1[2];
    uVar4 = nwk_network_status_to_str(cVar1);
    log_write(3,"nwk_nlme.c","NWK Status Indication: %s (0x%02x), addr 0x%04x",uVar4,cVar1,
              *(undefined2 *)(param_1 + 4));
    return;
  }
  if (*param_1 == '\x01') {
    log_write(3,"nwk_nlme.c","Permit Joining: duration %d",param_1[2]);
    return;
  }
  pcVar3 = nwk_handle_network_status_local;
  pbVar5 = (byte *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x65,
                                 "nwk_nlme_event_indication",&_LC18);
  bVar2 = *pbVar5;
  pcStack_18 = param_1;
  pcStack_14 = pcVar3;
  if (bVar2 == 0xd) {
    nwk_address_conflict_resolve(*(undefined2 *)(pbVar5 + 1));
    return;
  }
  if (bVar2 < 0xe) {
    pbVar6 = pbVar5;
    if (bVar2 != 0xb) {
      if (bVar2 < 0xc) {
        if (bVar2 < 3) {
          nwk_route_table_remove_by_dst(*(undefined2 *)(pbVar5 + 1));
          return;
        }
        if (bVar2 == 9) goto _L0;
      }
      else if (bVar2 == 0xc) {
        nwk_concentrator_discovery();
        goto _L0;
      }
      goto _L0;
    }
  }
  else {
    if (bVar2 == 0x13) {
      return;
    }
    if (bVar2 < 0x14) {
      if ((byte)(bVar2 - 0xf) < 2) {
        ds_save_common_data();
        goto _L0;
      }
    }
    else if (bVar2 == 0x14) goto _L0;
_L0:
    pbVar6 = (byte *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0xb8,
                                   "nwk_handle_network_status_local",&_LC18);
  }
  nwk_route_record_table_remove_by_dst(CONCAT11(pbVar5[2],pbVar6[1]));
_L0:
  iStack_28 = (uint)*pbVar5 << 0x10;
  uStack_24 = (uint)*(ushort *)(pbVar5 + 1);
  nwk_nlme_event_indication(&iStack_28);
  return;
}

