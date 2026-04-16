/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_asso_rsp_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: hdr */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_err_t prepare_asso_rsp_msg(mac_device *dev,zmsg_t *msg,mac_associate_rsp_t *rsp)

{
  undefined4 uVar1;
  ezb_err_t eVar2;
  undefined1 *puVar3;
  ezb_shortaddr_t aeStack_46 [2];
  ezb_panid_t eStack_42;
  mac_panids_t panids;
  mac_addresses_t addresses;
  uint8_t hdr [28];
  
  addresses.destination.u._4_4_ = 0;
  panids.source._0_1_ = 3;
  panids.destination = *(ezb_panid_t *)&(dev->pib).extended_address.field_0;
  addresses.source._0_2_ = *(undefined2 *)((int)&(dev->pib).extended_address.field_0 + 2);
  addresses.source.u.short_addr =
       *(ezb_shortaddr_t *)((int)&(dev->pib).extended_address.field_0 + 4);
  addresses.source.u.group_addr.bcast =
       *(ezb_shortaddr_t *)((int)&(dev->pib).extended_address.field_0 + 6);
  addresses.source.u._4_1_ = 3;
  addresses.source.u._6_2_ = *(undefined2 *)&(rsp->device_address).field_0;
  addresses.destination._0_2_ = *(undefined2 *)((int)&(rsp->device_address).field_0 + 2);
  addresses.destination.u.short_addr = *(ezb_shortaddr_t *)((int)&(rsp->device_address).field_0 + 4)
  ;
  addresses.destination.u.group_addr.bcast =
       *(ezb_shortaddr_t *)((int)&(rsp->device_address).field_0 + 6);
  aeStack_46[1] = 0xffff;
  eStack_42 = (dev->pib).panid;
  puVar3 = (undefined1 *)((int)&addresses.destination.u + 4);
  uVar1 = mac_frame_write_hdr(puVar3,&panids,aeStack_46 + 1,0,2);
  eVar2 = zmsg_append_bytes(msg,uVar1,puVar3);
  if (eVar2 == 0) {
    aeStack_46[0] = rsp->asso_shortaddr;
    eVar2 = zmsg_append_bytes(msg,2,aeStack_46);
    if (eVar2 == 0) {
      aeStack_46[0] = CONCAT11(aeStack_46[0]._1_1_,rsp->status);
      eVar2 = zmsg_append_bytes(msg,1,aeStack_46);
    }
  }
  return eVar2;
}

