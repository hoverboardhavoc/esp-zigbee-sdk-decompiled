/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    req.extpanid.field_0.u8[6] = '\0';
    req.extpanid.field_0.u64._4_2_ = 0x8400;
    iVar2 = core_globals_get();
    if (*(char *)(iVar2 + 0x9ee) != '\0') {
      req.extpanid.field_0.u64._4_2_ = req.extpanid.field_0.u64._4_2_ | 0x800;
    }
    iVar2 = nwk_is_device_zczr();
    if (iVar2 != 0) {
      req.extpanid.field_0.u64._4_2_ = req.extpanid.field_0.u64._4_2_ | 0x200;
    }
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

