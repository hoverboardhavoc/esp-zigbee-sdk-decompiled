/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_mcps_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_mcps_data_request(mac_interface_t *iface,mac_data_req_t *req)

{
  ezb_panid_t eVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  mac_device *dev;
  zmsg_t *msg;
  ezb_panid_t local_40;
  ezb_panid_t eStack_3e;
  mac_panids_t panids;
  uint8_t hdr [28];
  
  dev = (mac_device *)iface->dev;
  iVar2 = 3;
  if ((((*(uint *)&(dev->ctx).field_0x70 & 1) != 0) && (iVar2 = 2, req != (mac_data_req_t *)0x0)) &&
     (msg = req->msdu, msg != (zmsg_t *)0x0)) {
    eVar1 = (dev->pib).panid;
    memset(&panids,0,0x1c);
    eStack_3e = req->dst_panid;
    local_40 = eVar1;
    uVar3 = mac_frame_write_hdr(&panids,&req->addresses,&local_40,0,1,0);
    iVar2 = zmsg_prepend_bytes(msg,uVar3,&panids);
    if (iVar2 == 0) {
      uVar4 = zmsg_get_length(msg);
      if (uVar4 < 0x7e) {
        if ((req->field_0x1a & 2) == 0) {
          zmsg_queue_enqueue(&(dev->ctx).tx_q,msg);
          if (((dev->ctx).cur_op != '\x04') && (((dev->ctx).pending_ops & 0x10) == 0)) {
            mac_start_op(dev,MAC_OPERATION_TRANSMIT_DATA_DIRECT);
          }
        }
        else {
          mac_indirect_transmit(dev,&(req->addresses).destination,msg);
        }
      }
      else {
        iVar2 = 4;
      }
    }
  }
  return iVar2;
}

