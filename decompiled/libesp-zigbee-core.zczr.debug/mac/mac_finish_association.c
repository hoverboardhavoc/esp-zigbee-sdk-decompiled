/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_finish_association
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_finish_association(mac_device *dev,mac_associate_cnf_t *asso_cnf)

{
  ezb_panid_t panid;
  ezb_shortaddr_t short_address;
  
  mac_set_state(dev,MAC_STATE_NORMAL);
  if (asso_cnf->status == '\0') {
    panid = (dev->pib).panid;
    short_address = asso_cnf->asso_shortaddr;
    mac_set_pan_channel(dev,(dev->ctx).phy_channel_page,(dev->ctx).phy_channel);
  }
  else {
    panid = 0xffff;
    short_address = panid;
  }
  mac_set_panid(dev,panid);
  mac_set_short_address(dev,short_address);
  nwk_mm_asso_confirm((dev->ctx).iface_id,asso_cnf);
  return;
}

