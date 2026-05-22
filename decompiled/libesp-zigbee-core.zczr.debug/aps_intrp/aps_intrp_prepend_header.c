/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> aps_intrp_prepend_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_intrp_prepend_header(zmsg_t *msg,aps_intrp_data_req_t *req)

{
  ezb_addr_mode_t eVar1;
  uint16_t uVar2;
  ezb_shortaddr_t eVar3;
  undefined4 uVar4;
  ezb_err_t eVar5;
  byte bVar6;
  undefined1 *puVar7;
  undefined4 uStack_18;
  uint8_t aps_hdr [7];
  
  uStack_18 = 0;
  aps_hdr[0] = '\0';
  aps_hdr[1] = '\0';
  aps_hdr[2] = '\0';
  if ((msg == (zmsg_t *)0x0) || (req == (aps_intrp_data_req_t *)0x0)) {
    req = (aps_intrp_data_req_t *)
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/interpan/aps_intrp.c",0x34,
                        "aps_intrp_prepend_header","msg && req");
  }
  else {
    eVar1 = (req->dst_addr).addr_mode;
    if (eVar1 == '\x01') {
      bVar6 = 0xf;
      goto _L0;
    }
    if (eVar1 != '\x02') {
      bVar6 = 3;
      goto _L0;
    }
  }
  if ((req->dst_addr).u.short_addr < 0xfff8) {
    bVar6 = 3;
  }
  else {
    bVar6 = 0xb;
  }
_L0:
  uVar4 = uStack_18;
  uStack_18 = CONCAT31(uStack_18._1_3_,bVar6);
  if ((bVar6 & 0xc) == 0xc) {
    eVar3 = (req->dst_addr).u.short_addr;
    uStack_18._3_1_ = SUB41(uVar4,3);
    uStack_18._0_3_ = CONCAT12((char)(eVar3 >> 8),CONCAT11((char)eVar3,bVar6));
    puVar7 = (undefined1 *)((int)&uStack_18 + 3);
  }
  else {
    puVar7 = (undefined1 *)((int)&uStack_18 + 1);
  }
  uVar2 = req->cluster_id;
  *puVar7 = (char)uVar2;
  puVar7[1] = (char)(uVar2 >> 8);
  uVar2 = req->profile_id;
  puVar7[2] = (char)uVar2;
  puVar7[3] = (char)(uVar2 >> 8);
  eVar5 = zmsg_prepend_bytes((uint)(puVar7 + (4 - (int)&uStack_18)) & 0xffff);
  return eVar5;
}

