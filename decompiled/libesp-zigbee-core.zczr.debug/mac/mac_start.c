/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_start(mac_device *dev,mac_start_req_t *req)

{
  _Bool _Var1;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  
  _Var1 = mac_is_enabled(dev);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    eVar2 = 3;
  }
  else if (req == (mac_start_req_t *)0x0) {
    eVar2 = 2;
  }
  else if ((dev->pib).short_address == 0xffff) {
    eVar2 = 0x1ec;
  }
  else if (req->pan_id == 0xffff) {
    eVar2 = 0x1e8;
  }
  else {
    eVar2 = mac_set_pan_channel(dev,req->channel_page,req->logical_channel);
    if (eVar2 == 0) {
      mac_set_pan_coord(dev,(_Bool)((byte)*(undefined2 *)&req->field_0x4 & 1));
      mac_set_panid(dev,req->pan_id);
      eVar2 = 0;
    }
    else {
      eVar2 = 0;
    }
  }
  return eVar2;
}

