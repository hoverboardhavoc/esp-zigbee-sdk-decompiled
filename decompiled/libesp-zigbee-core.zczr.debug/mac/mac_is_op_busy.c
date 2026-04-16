/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_is_op_busy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool mac_is_op_busy(mac_device *dev,mac_operation_t op)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int iVar2;
  
  if ((dev->ctx).cur_op == op) {
    iVar2 = 1;
  }
  else {
    _Var1 = mac_is_op_pending(dev,op);
    iVar2 = CONCAT31(extraout_var,_Var1);
    if (iVar2 != 0) {
      iVar2 = 1;
    }
  }
  return SUB41(iVar2,0);
}

