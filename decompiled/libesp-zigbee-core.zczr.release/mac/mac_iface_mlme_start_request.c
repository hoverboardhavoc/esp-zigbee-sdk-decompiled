/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_mlme_start_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_mlme_start_request(mac_interface_t *iface,mac_start_req_t *req)

{
  uint8_t uVar1;
  uint8_t uVar2;
  ezb_panid_t panid;
  mac_device *dev;
  ezb_err_t eVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  dev = (mac_device *)iface->dev;
  eVar3 = 3;
  if (((((*(uint *)&(dev->ctx).field_0x70 & 1) != 0) && (eVar3 = 2, req != (mac_start_req_t *)0x0))
      && (eVar3 = 0x1ec, (dev->pib).short_address != 0xffff)) &&
     (eVar3 = 0x1e8, req->pan_id != 0xffff)) {
    eVar3 = mac_set_pan_channel(dev,req->channel_page,req->logical_channel);
    if (eVar3 == 0) {
      if ((*(ushort *)&req->field_0x4 & 1) == 0) {
        (dev->pib).coord_shortaddr = 0xffff;
        uVar4 = 0;
        uVar5 = 0;
      }
      else {
        uVar1 = (dev->pib).extended_address.field_0.u8[1];
        uVar2 = (dev->pib).extended_address.field_0.u8[4];
        (dev->pib).coord_shortaddr = (dev->pib).short_address;
        uVar4 = CONCAT13((dev->pib).extended_address.field_0.u8[3],
                         CONCAT12((dev->pib).extended_address.field_0.u8[2],
                                  CONCAT11(uVar1,(dev->pib).extended_address.field_0.u8[0])));
        uVar5 = CONCAT13((dev->pib).extended_address.field_0.u8[7],
                         CONCAT12((dev->pib).extended_address.field_0.u8[6],
                                  CONCAT11((dev->pib).extended_address.field_0.u8[5],uVar2)));
      }
      (dev->pib).coord_extaddr.field_0.u8[0] = (uint8_t)uVar4;
      (dev->pib).coord_extaddr.field_0.u8[1] = (uint8_t)((uint)uVar4 >> 8);
      (dev->pib).coord_extaddr.field_0.u8[3] = (uint8_t)((uint)uVar4 >> 0x18);
      panid = req->pan_id;
      (dev->pib).coord_extaddr.field_0.u8[4] = (uint8_t)uVar5;
      (dev->pib).coord_extaddr.field_0.u8[5] = (uint8_t)((uint)uVar5 >> 8);
      (dev->pib).coord_extaddr.field_0.u8[2] = (uint8_t)((uint)uVar4 >> 0x10);
      (dev->pib).coord_extaddr.field_0.u8[6] = (uint8_t)((uint)uVar5 >> 0x10);
      (dev->pib).coord_extaddr.field_0.u8[7] = (uint8_t)((uint)uVar5 >> 0x18);
      mac_set_panid(dev,panid);
    }
    eVar3 = 0;
  }
  return eVar3;
}

