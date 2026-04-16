/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_call_join_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_call_join_confirm(nwk_join_method_t method,ezb_err_t error)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uStack_1c;
  nwk_join_cnf_t cnf;
  
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xac0) = 0;
  cnf.status = '\0';
  cnf.join_method = '\0';
  cnf.network_address = 0;
  cnf.extended_panid.field_0.u64._0_4_ = 0;
  uStack_1c._0_2_ = CONCAT11(method,(char)error);
  uStack_1c = (uint)(ushort)uStack_1c;
  if (error == 0) {
    uVar1 = nwk_get_short_address();
  }
  else {
    uVar1 = 0xffff;
  }
  uStack_1c = CONCAT22(uVar1,(ushort)uStack_1c);
  puVar3 = (undefined4 *)nwk_get_extended_panid();
  cnf._0_4_ = *puVar3;
  cnf.extended_panid.field_0.u64._0_4_ = puVar3[1];
  nwk_join_confirm(&uStack_1c);
  return;
}

