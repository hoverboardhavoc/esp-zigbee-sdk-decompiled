/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_data_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t prepare_data_msg(mac_device *dev,zmsg_t *msg,mac_data_req_t *req)

{
  undefined4 uVar1;
  ezb_err_t eVar2;
  ezb_panid_t local_30;
  ezb_panid_t eStack_2e;
  mac_panids_t panids;
  uint8_t hdr [28];
  
  panids.source = 0;
  panids.destination = 0;
  local_30 = (dev->pib).panid;
  eStack_2e = req->dst_panid;
  uVar1 = mac_frame_write_hdr(&panids,&req->addresses,&local_30,0,1,0);
  eVar2 = zmsg_prepend_bytes(msg,uVar1,&panids);
  return eVar2;
}

