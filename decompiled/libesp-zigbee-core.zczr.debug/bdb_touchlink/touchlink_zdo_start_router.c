/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_start_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_zdo_start_router(touchlink_event_start_router_t *start_router)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  ezb_err_t eVar13;
  char *pcVar14;
  undefined1 *puVar15;
  void *__src;
  undefined2 auStack_12 [2];
  nwk_addr_ref_t addr_ref;
  
  if (start_router == (touchlink_event_start_router_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",0x25,
                  "touchlink_zdo_start_router","start_router");
  }
  else {
    nwk_set_extended_panid(&start_router->ext_panid);
    nwk_set_pan_channel(1 << (start_router->channel & 0x1f) & 0x7ffffff);
    nwk_set_panid(start_router->pan_id);
    nwk_set_short_address(start_router->new_short_addr);
    uVar9 = nwk_get_extended_address();
    uVar10 = touchlink_short_address();
    iVar11 = nwk_address_update(uVar9,uVar10,auStack_12);
    if (iVar11 == 0) {
      nwk_address_lock_ref(auStack_12[0]);
      iVar11 = core_globals_get();
      *(byte *)(iVar11 + 0xb18) = *(byte *)(iVar11 + 0xb18) | 1;
      nwk_secur_set_key(start_router->nwk_key,0);
      nwk_secur_switch_key(0);
      zdo_initiate_commissioning(0x80);
      return 0;
    }
  }
  iVar11 = __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",0x36,
                         "touchlink_zdo_start_router",
                         "(nwk_address_update(nwk_get_extended_address(), touchlink_short_address(), &addr_ref)) == 0"
                        );
  iVar12 = touchlink_commissioning_get();
  if (*(char *)(iVar12 + 1) == '\x01') {
    if (iVar11 != 0) {
      eVar13 = touchlink_commissioning_task_result(1);
      return eVar13;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",0x11b,
                  "touchlink_initiator_process_discovery_done",
                  "(*touchlink_commissioning_get()).role == TL_COMM_ROLE_INITIATOR");
  }
  pcVar14 = (char *)touchlink_commissioning_get();
  if (*pcVar14 == '\x03') {
    iVar11 = touchlink_transaction_get();
    *(undefined1 *)(iVar11 + 0x60c) = 5;
    iVar11 = touchlink_transaction_get();
    *(undefined1 *)(iVar11 + 0x610) = 0;
    iVar11 = touchlink_transaction_get();
    uVar7 = touchlink_get_logical_channel();
    *(undefined1 *)(iVar11 + 0x61c) = uVar7;
    iVar11 = touchlink_transaction_get();
    uVar8 = touchlink_assign_pan_id();
    *(undefined2 *)(iVar11 + 0x61a) = uVar8;
    iVar11 = touchlink_transaction_get();
    uVar8 = touchlink_assign_short_addr();
    *(undefined2 *)(iVar11 + 0x61e) = uVar8;
    iVar11 = touchlink_transaction_get();
    puVar15 = (undefined1 *)touchlink_extended_address();
    uVar7 = puVar15[1];
    uVar1 = puVar15[2];
    uVar2 = puVar15[3];
    uVar3 = puVar15[4];
    uVar4 = puVar15[5];
    uVar5 = puVar15[6];
    uVar6 = puVar15[7];
    *(undefined1 *)(iVar11 + 0x611) = *puVar15;
    *(undefined1 *)(iVar11 + 0x612) = uVar7;
    *(undefined1 *)(iVar11 + 0x613) = uVar1;
    *(undefined1 *)(iVar11 + 0x614) = uVar2;
    *(undefined1 *)(iVar11 + 0x615) = uVar3;
    *(undefined1 *)(iVar11 + 0x616) = uVar4;
    *(undefined1 *)(iVar11 + 0x617) = uVar5;
    *(undefined1 *)(iVar11 + 0x618) = uVar6;
    iVar11 = touchlink_transaction_get();
    __src = (void *)touchlink_nwk_key();
    memcpy((void *)(iVar11 + 0x620),__src,0x10);
  }
  iVar11 = touchlink_transaction_get();
  eVar13 = touchlink_zdo_start_router((touchlink_event_start_router_t *)(iVar11 + 0x610));
  return eVar13;
}

