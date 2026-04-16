/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_beacon
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: addresses */
/* WARNING: Unknown calling convention */

ezb_err_t prepare_beacon(mac_device *dev,ezb_radio_frame_t *tx_frame)

{
  char cVar1;
  _Bool _Var2;
  uint8_t uVar3;
  int iVar4;
  undefined3 extraout_var;
  ushort uVar5;
  uint8_t *puVar6;
  mac_beacon_t *beacon;
  ezb_panid_t aeStack_28 [2];
  mac_panids_t panids;
  mac_addresses_t addresses;
  
  panids.destination = (dev->pib).short_address;
  panids.source = 2;
  aeStack_28[0] = (dev->pib).panid;
  aeStack_28[1] = 0xffff;
  cVar1 = mac_frame_write_hdr(tx_frame->psdu,&panids,aeStack_28,0,0,0);
  tx_frame->length = cVar1 + '\x02';
  (dev->pib).bsn = (dev->pib).bsn + '\x01';
  mac_frame_set_seq_num(tx_frame);
  puVar6 = tx_frame->psdu;
  iVar4 = mac_frame_find_payload_index(tx_frame);
  beacon = (mac_beacon_t *)(puVar6 + iVar4);
  _Var2 = mac_is_pan_coord(dev);
  if (CONCAT31(extraout_var,_Var2) == 0) {
    uVar5 = 0xfff;
  }
  else {
    uVar5 = 0x4fff;
  }
  if ((*(ushort *)&(dev->pib).field_0x2a & 1) != 0) {
    uVar5 = uVar5 | 0x8000;
  }
  *(char *)&beacon->superframe_spec = (char)uVar5;
  *(char *)((int)&beacon->superframe_spec + 1) = (char)(uVar5 >> 8);
  beacon->gts_spec = '\0';
  beacon->pending_addr_spec = '\0';
  tx_frame->length = tx_frame->length + '\x04';
  uVar3 = mac_beacon_set_payload(beacon,(dev->pib).beacon_payload,(dev->pib).beacon_payload_len);
  tx_frame->length = tx_frame->length + uVar3;
  return 0;
}

