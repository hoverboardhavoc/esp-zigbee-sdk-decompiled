/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_mcps_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_mcps_data_request(mac_interface_t *iface,mac_data_req_t *req)

{
  zmsg_t *msg;
  _Bool _Var1;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  uint uVar3;
  mac_device *dev;
  
  dev = (mac_device *)iface->dev;
  _Var1 = mac_is_enabled(dev);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    msg = (zmsg_t *)0x0;
    eVar2 = 3;
  }
  else if (req == (mac_data_req_t *)0x0) {
    eVar2 = 2;
    msg = (zmsg_t *)0x0;
  }
  else {
    msg = req->msdu;
    if (msg == (zmsg_t *)0x0) {
      eVar2 = 2;
    }
    else {
      eVar2 = prepare_data_msg(dev,msg,req);
      if (eVar2 == 0) {
        uVar3 = zmsg_get_length(msg);
        if (uVar3 < 0x7e) {
          if ((req->field_0x1a & 2) != 0) {
            mac_indirect_transmit(dev,&(req->addresses).destination,msg);
            return 0;
          }
          mac_direct_transmit(dev,msg);
          return 0;
        }
        eVar2 = 4;
      }
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return eVar2;
}

