/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_poll(mac_device *dev,mac_poll_req_t *req)

{
  ezb_addr_mode_t eVar1;
  ezb_shortaddr_t eVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  _Bool _Var5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  ezb_err_t eVar6;
  
  _Var5 = mac_is_enabled(dev);
  if (CONCAT31(extraout_var,_Var5) == 0) {
    eVar6 = 3;
  }
  else if ((dev->ctx).state == '\x02') {
    eVar6 = 3;
  }
  else {
    _Var5 = mac_is_op_busy(dev,MAC_OPERATION_TRANSMIT_POLL);
    if (CONCAT31(extraout_var_00,_Var5) == 0) {
      if ((req != (mac_poll_req_t *)0x0) &&
         (_Var5 = mac_is_associated(dev), CONCAT31(extraout_var_01,_Var5) == 0)) {
        eVar1 = (req->coord_address).addr_mode;
        if (eVar1 == '\x02') {
          (dev->pib).coord_shortaddr = (req->coord_address).u.short_addr;
        }
        else {
          if (eVar1 != '\x03') {
            return 2;
          }
          eVar2 = (req->coord_address).u.group_addr.bcast;
          uVar3 = *(undefined2 *)((int)&(req->coord_address).u + 4);
          uVar4 = *(undefined2 *)((int)&(req->coord_address).u + 6);
          *(ezb_shortaddr_t *)&(dev->pib).coord_extaddr.field_0 = (req->coord_address).u.short_addr;
          *(ezb_shortaddr_t *)((int)&(dev->pib).coord_extaddr.field_0 + 2) = eVar2;
          *(undefined2 *)((int)&(dev->pib).coord_extaddr.field_0 + 4) = uVar3;
          *(undefined2 *)((int)&(dev->pib).coord_extaddr.field_0 + 6) = uVar4;
        }
        mac_set_panid(dev,req->coord_panid);
      }
      mac_start_op(dev,MAC_OPERATION_TRANSMIT_POLL);
      eVar6 = 0;
    }
    else {
      eVar6 = 0;
    }
  }
  return eVar6;
}

