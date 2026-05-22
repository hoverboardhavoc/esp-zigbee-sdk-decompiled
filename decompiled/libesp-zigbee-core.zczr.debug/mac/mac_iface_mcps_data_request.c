/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_mcps_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_mcps_data_request(mac_interface_t *iface,mac_data_req_t *req)

{
  _Bool _Var1;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  uint uVar3;
  mac_device *dev;
  zmsg_t *msg;
  
  dev = (mac_device *)iface->dev;
  _Var1 = mac_is_enabled(dev);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    eVar2 = 3;
  }
  else if (req == (mac_data_req_t *)0x0) {
    eVar2 = 2;
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
          if ((req->field_0x1a & 2) == 0) {
            mac_direct_transmit(dev,msg);
          }
          else {
            mac_indirect_transmit(dev,&(req->addresses).destination,msg);
          }
        }
        else {
          eVar2 = 4;
        }
      }
    }
  }
  return eVar2;
}

