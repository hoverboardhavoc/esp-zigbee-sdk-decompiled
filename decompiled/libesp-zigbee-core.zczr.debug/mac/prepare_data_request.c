/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t prepare_data_request(mac_device *dev,ezb_radio_frame_t *tx_frame)

{
  ushort uVar1;
  char cVar2;
  ezb_panid_t eStack_28;
  ezb_panid_t eStack_26;
  mac_panids_t panids;
  mac_addresses_t addresses;
  
  panids.source._0_1_ = 3;
  eStack_28 = (dev->pib).panid;
  uVar1 = (dev->pib).short_address;
  panids.destination = *(ezb_panid_t *)&(dev->pib).extended_address.field_0;
  if (uVar1 < 0xfffe) {
    panids.source._0_1_ = 2;
    panids.destination = uVar1;
  }
  eStack_26 = eStack_28;
  cVar2 = mac_frame_write_hdr(tx_frame->psdu,&panids,&eStack_28,0,3,4);
  tx_frame->length = cVar2 + '\x02';
  (dev->pib).dsn = (dev->pib).dsn + '\x01';
  mac_frame_set_seq_num(tx_frame);
  return 0;
}

