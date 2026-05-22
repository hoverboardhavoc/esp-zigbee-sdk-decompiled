/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_join_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_join_request(nwk_join_req_t *req)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  nwk_rejoin_method_t nVar8;
  uint8_t uVar9;
  undefined1 uVar10;
  byte bVar11;
  ezb_err_t eVar12;
  int iVar13;
  
  if (req != (nwk_join_req_t *)0x0) {
    iVar13 = core_globals_get();
    if (*(char *)(iVar13 + 0xac0) != '\0') {
      eVar12 = 3;
      goto _L0;
    }
    iVar13 = nwk_is_joined();
    if ((iVar13 != 0) && (req->rejoin_network == '\0')) {
      eVar12 = 0x2c2;
      goto _L0;
    }
    iVar13 = core_globals_get();
    uVar1 = (req->extpanid).field_0.u8[1];
    uVar2 = (req->extpanid).field_0.u8[2];
    uVar3 = (req->extpanid).field_0.u8[3];
    uVar4 = (req->extpanid).field_0.u8[4];
    uVar5 = (req->extpanid).field_0.u8[5];
    uVar6 = (req->extpanid).field_0.u8[6];
    uVar7 = (req->extpanid).field_0.u8[7];
    nVar8 = req->rejoin_network;
    uVar9 = req->capability_info;
    uVar10 = req->field_0xa;
    *(uint8_t *)(iVar13 + 0xac8) = (req->extpanid).field_0.u8[0];
    *(uint8_t *)(iVar13 + 0xac9) = uVar1;
    *(uint8_t *)(iVar13 + 0xaca) = uVar2;
    *(uint8_t *)(iVar13 + 0xacb) = uVar3;
    *(uint8_t *)(iVar13 + 0xacc) = uVar4;
    *(uint8_t *)(iVar13 + 0xacd) = uVar5;
    *(uint8_t *)(iVar13 + 0xace) = uVar6;
    *(uint8_t *)(iVar13 + 0xacf) = uVar7;
    *(nwk_rejoin_method_t *)(iVar13 + 0xad0) = nVar8;
    *(uint8_t *)(iVar13 + 0xad1) = uVar9;
    *(undefined1 *)(iVar13 + 0xad2) = uVar10;
    iVar13 = core_globals_get();
    *(undefined1 *)(iVar13 + 0xac0) = 2;
    iVar13 = core_globals_get();
    milli_timer_init(iVar13 + 0xad4,nwk_handle_attach_timer,0);
    bVar11 = req->rejoin_network;
    if (bVar11 == 2) {
_L0:
      eVar12 = nwk_do_attach(req);
      if (eVar12 == 0) {
        return 0;
      }
      goto _L0;
    }
    if (bVar11 < 3) {
      if (bVar11 == 0) goto _L0;
      if (bVar11 == 1) {
        eVar12 = 6;
        goto _L0;
      }
    }
    else if (bVar11 == 3) {
      eVar12 = 6;
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x1e9,
                  "nwk_join_request",&_LC1);
  }
  eVar12 = 2;
_L0:
  iVar13 = core_globals_get();
  *(undefined1 *)(iVar13 + 0xac0) = 0;
  return eVar12;
}

