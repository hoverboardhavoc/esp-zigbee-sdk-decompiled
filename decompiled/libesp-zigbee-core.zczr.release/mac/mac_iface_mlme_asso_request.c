/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_mlme_asso_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_mlme_asso_request(mac_interface_t *iface,mac_associate_req_t *req)

{
  ezb_addr_mode_t eVar1;
  ezb_err_t eVar2;
  mac_device *dev;
  
  dev = (mac_device *)iface->dev;
  if ((*(uint *)&(dev->ctx).field_0x70 & 1) == 0) {
    return 3;
  }
  eVar2 = 3;
  if ((((dev->pib).short_address == 0xffff) && (eVar2 = 9, (dev->ctx).state == '\0')) &&
     (eVar2 = 2, req != (mac_associate_req_t *)0x0)) {
    eVar1 = (req->coord_address).addr_mode;
    if (eVar1 == '\x02') {
      (dev->pib).coord_shortaddr = (req->coord_address).u.short_addr;
    }
    else {
      if (eVar1 != '\x03') {
        return 2;
      }
      memcpy(&(dev->pib).coord_extaddr,&(req->coord_address).u,8);
    }
    mac_set_panid(dev,req->coord_panid);
    (dev->ctx).phy_channel_page = req->channel_page;
    (dev->ctx).phy_channel = req->logical_channel;
    (dev->ctx).mac_cap_info = req->capability;
    mac_start_op(dev,MAC_OPERATION_TRANSMIT_ASSO_REQ);
    eVar2 = 0;
  }
  return eVar2;
}

