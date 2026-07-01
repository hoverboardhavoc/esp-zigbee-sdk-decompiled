/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_join
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_comm_join(void)

{
  int iVar1;
  int iVar2;
  ezb_err_t eVar3;
  byte bVar4;
  undefined4 uStack_1c;
  nwk_join_req_t req;
  
  iVar1 = nwk_disc_table_next(0);
  if (iVar1 == 0) {
    eVar3 = 0x1ea;
  }
  else {
    uStack_1c = 0;
    req.extpanid.field_0.u64._0_4_ = 0;
    req.extpanid.field_0.u64._4_2_ = 0;
    req.extpanid.field_0.u8[6] = '\0';
    iVar2 = af_get_node_desc();
    req.extpanid.field_0.u8[5] = *(undefined1 *)(iVar2 + 2);
    nwk_address_get_extpanid(*(undefined1 *)(iVar1 + 8),&uStack_1c);
    iVar1 = core_globals_get();
    bVar4 = *(byte *)(iVar1 + 0xcdc) & 1;
    if ((*(byte *)(iVar1 + 0xcdc) & 1) != 0) {
      bVar4 = 2;
    }
    req.extpanid.field_0.u8[4] = bVar4;
    iVar1 = core_globals_get();
    req.extpanid.field_0.u8[6] =
         req.extpanid.field_0.u8[6] & 0xfe | *(char *)(iVar1 + 0xcc0) == '\x03';
    eVar3 = nwk_join_request(&uStack_1c);
  }
  return eVar3;
}

