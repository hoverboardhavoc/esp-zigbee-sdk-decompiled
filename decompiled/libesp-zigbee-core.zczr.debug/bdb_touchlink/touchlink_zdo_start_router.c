/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_start_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_zdo_start_router(int param_1)

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
  char *pcVar13;
  undefined1 *puVar14;
  void *__src;
  undefined2 auStack_12 [3];
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                  0x25,"touchlink_zdo_start_router","start_router");
  }
  else {
    nwk_set_extended_panid(param_1 + 1);
    nwk_set_pan_channel(1 << (*(byte *)(param_1 + 0xc) & 0x1f) & 0x7ffffff);
    nwk_set_panid(*(undefined2 *)(param_1 + 10));
    nwk_set_short_address(*(undefined2 *)(param_1 + 0xe));
    uVar9 = nwk_get_extended_address();
    uVar10 = touchlink_short_address();
    iVar11 = nwk_address_update(uVar9,uVar10,auStack_12);
    if (iVar11 == 0) {
      nwk_address_lock_ref(auStack_12[0]);
      iVar11 = core_globals_get();
      *(byte *)(iVar11 + 0xb18) = *(byte *)(iVar11 + 0xb18) | 1;
      nwk_secur_set_key(param_1 + 0x10,0);
      nwk_secur_switch_key(0);
      zdo_initiate_commissioning(0x80);
      return 0;
    }
  }
  iVar11 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c"
                         ,0x36,"touchlink_zdo_start_router",
                         "(nwk_address_update(nwk_get_extended_address(), touchlink_short_address(), &addr_ref)) == 0"
                        );
  iVar12 = touchlink_commissioning_get();
  if (*(char *)(iVar12 + 1) == '\x01') {
    if (iVar11 != 0) {
      uVar9 = touchlink_commissioning_task_result(1);
      return uVar9;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                  0x127,"touchlink_initiator_process_discovery_done",
                  "(*touchlink_commissioning_get()).role == TL_COMM_ROLE_INITIATOR");
  }
  pcVar13 = (char *)touchlink_commissioning_get();
  if (*pcVar13 == '\x03') {
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
    puVar14 = (undefined1 *)touchlink_extended_address();
    uVar7 = puVar14[1];
    uVar1 = puVar14[2];
    uVar2 = puVar14[3];
    uVar3 = puVar14[4];
    uVar4 = puVar14[5];
    uVar5 = puVar14[6];
    uVar6 = puVar14[7];
    *(undefined1 *)(iVar11 + 0x611) = *puVar14;
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
  uVar9 = touchlink_zdo_start_router(iVar11 + 0x610);
  return uVar9;
}

