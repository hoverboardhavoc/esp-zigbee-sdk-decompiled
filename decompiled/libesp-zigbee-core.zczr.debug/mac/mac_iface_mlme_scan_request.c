/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_mlme_scan_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_mlme_scan_request(mac_interface_t *iface,mac_scan_req_t *req)

{
  byte bVar1;
  ezb_err_t eVar2;
  
  bVar1 = req->scan_type;
  if (bVar1 == 1) {
    eVar2 = mac_active_scan((mac_device *)iface->dev,req->scan_channels,(ushort)req->scan_duration,
                            (req->cb_u).active_scan_cb,req->user_ctx);
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      eVar2 = mac_ed_scan((mac_device *)iface->dev,req->scan_channels,(ushort)req->scan_duration,
                          (req->cb_u).ed_scan_cb,req->user_ctx);
    }
    else {
      eVar2 = 2;
    }
  }
  else if ((byte)(bVar1 - 2) < 3) {
    eVar2 = 6;
  }
  else {
    eVar2 = 2;
  }
  return eVar2;
}

