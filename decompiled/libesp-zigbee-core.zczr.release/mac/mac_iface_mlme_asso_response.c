/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_mlme_asso_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_mlme_asso_response(mac_interface_t *iface,mac_associate_rsp_t *rsp)

{
  int iVar1;
  zmsg_t *msg;
  undefined4 uVar2;
  mac_device *dev;
  ezb_shortaddr_t aeStack_56 [2];
  ezb_panid_t eStack_52;
  mac_panids_t panids;
  mac_addresses_t addresses;
  uint8_t hdr [28];
  
  dev = (mac_device *)iface->dev;
  msg = (zmsg_t *)zmsg_alloc(0);
  iVar1 = 1;
  if (msg != (zmsg_t *)0x0) {
    memset((void *)((int)&addresses.destination.u + 4),0,0x1c);
    panids.source._0_1_ = 3;
    memcpy(&panids.destination,dev,8);
    addresses.source.u._4_1_ = 3;
    memcpy((void *)((int)&addresses.source.u + 6),rsp,8);
    aeStack_56[1] = 0xffff;
    eStack_52 = (dev->pib).panid;
    uVar2 = mac_frame_write_hdr((undefined1 *)((int)&addresses.destination.u + 4),&panids,
                                aeStack_56 + 1,0,3,2);
    iVar1 = zmsg_append_bytes(msg,uVar2,(undefined1 *)((int)&addresses.destination.u + 4));
    if (iVar1 == 0) {
      aeStack_56[0] = rsp->asso_shortaddr;
      iVar1 = zmsg_append_bytes(msg,2,aeStack_56);
      if (iVar1 == 0) {
        aeStack_56[0] = CONCAT11(aeStack_56[0]._1_1_,rsp->status);
        iVar1 = zmsg_append_bytes(msg,1,aeStack_56);
        if (iVar1 == 0) {
          addresses.destination.u._4_1_ = 3;
          memcpy((void *)((int)&addresses.destination.u + 6),rsp,8);
          mac_indirect_transmit(dev,(ezb_address_t *)((int)&addresses.destination.u + 4),msg);
          return 0;
        }
      }
    }
    zmsg_free(msg);
  }
  return iVar1;
}

