/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_mlme_asso_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_mlme_asso_response(mac_interface_t *iface,mac_associate_rsp_t *rsp)

{
  zmsg_t *msg;
  ezb_err_t eVar1;
  mac_device *dev;
  ezb_address_t aeStack_2c [2];
  
  dev = (mac_device *)iface->dev;
  msg = (zmsg_t *)zmsg_alloc(0);
  if (msg == (zmsg_t *)0x0) {
    eVar1 = 1;
  }
  else {
    eVar1 = prepare_asso_rsp_msg(dev,msg,rsp);
    if (eVar1 == 0) {
      aeStack_2c[0].addr_mode = '\x03';
      aeStack_2c[0].u._0_2_ = *(undefined2 *)&(rsp->device_address).field_0;
      aeStack_2c[0].u._2_2_ = *(ezb_shortaddr_t *)((int)&(rsp->device_address).field_0 + 2);
      aeStack_2c[0].u._4_2_ = *(undefined2 *)((int)&(rsp->device_address).field_0 + 4);
      aeStack_2c[0].u._6_2_ = *(undefined2 *)((int)&(rsp->device_address).field_0 + 6);
      mac_indirect_transmit(dev,aeStack_2c,msg);
      return 0;
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return eVar1;
}

