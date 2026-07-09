/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_do_attach
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_do_attach(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  undefined4 uStack_3c;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  byte bStack_30;
  byte bStack_2f;
  undefined1 uStack_2e;
  undefined2 uStack_2a;
  byte abStack_28 [6];
  undefined2 auStack_22 [7];
  
  iVar2 = nwk_address_get_panid_ref();
  if (iVar2 == 0xff) {
    return 0x2c3;
  }
  uVar3 = nwk_is_device_zed();
  puVar4 = (undefined2 *)nwk_choose_parent(iVar2,uVar3,*(char *)(param_1 + 8) == '\0');
  if (puVar4 == (undefined2 *)0x0) {
    return 0x2c3;
  }
  nwk_address_get_panid(iVar2,&uStack_2a);
  nwk_set_panid(uStack_2a);
  iVar2 = core_globals_get();
  *(undefined2 **)(iVar2 + 0xac4) = puVar4;
  bVar1 = *(byte *)(param_1 + 8);
  if (bVar1 == 0) {
    if (*(int *)(puVar4 + 8) << 0x13 < 0) {
      bVar1 = 3;
_L0:
      uVar5 = nwk_get_short_address();
      if ((0xfff7 < uVar5) || (iVar2 = nwk_get_short_address(), iVar2 == 0)) {
        nwk_assign_shortaddr();
        nwk_set_short_address();
      }
      uVar3 = nwk_get_extended_address();
      uVar6 = nwk_get_short_address();
      auStack_22[0] = 0;
      iVar2 = nwk_address_update(uVar3,uVar6,auStack_22);
      if (iVar2 != 0) goto _L0;
      uStack_3c = 1 << (*(uint *)(puVar4 + 8) & 0x1f) & 0x7ffffffU |
                  (*(uint *)(puVar4 + 8) >> 7) << 0x1b;
      iVar2 = nwk_mm_set_pib_attr(*(byte *)((int)puVar4 + 0x13) & 0x1f,0x61,&uStack_3c);
      if (iVar2 != 0) goto _L0;
      nwk_mm_set_pib_attr(*(byte *)((int)puVar4 + 0x13) & 0x1f,0x4b,puVar4);
    }
_L0:
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0xad3) = bVar1;
    if (bVar1 == 3) {
      uVar3 = nwk_send_network_comm_req(puVar4,0,0,*(undefined1 *)(param_1 + 9));
      return uVar3;
    }
    if (bVar1 < 4) {
      if (bVar1 == 0) {
        if (*(int *)(puVar4 + 8) << 2 < 0) {
          uVar7 = 2;
        }
        else {
          uVar7 = 3;
        }
        uStack_3c = CONCAT31(uStack_3c._1_3_,uVar7);
        uStack_38 = puVar4[1];
        uStack_36 = puVar4[2];
        uStack_34 = puVar4[3];
        uStack_3c = CONCAT22(*puVar4,(undefined2)uStack_3c);
        uStack_32 = uStack_2a;
        bStack_30 = (byte)(*(uint *)(puVar4 + 8) >> 7) & 0x1f;
        bStack_2f = (byte)*(undefined4 *)(puVar4 + 8) & 0x7f;
        uStack_2e = *(undefined1 *)(param_1 + 9);
        uVar3 = nwk_mm_asso_request(*(byte *)((int)puVar4 + 0x13) & 0x1f,&uStack_3c);
        return uVar3;
      }
      if ((byte)(bVar1 - 1) < 2) {
        uVar3 = nwk_send_rejoin_req(puVar4,*(byte *)(param_1 + 10) & 1,*(undefined1 *)(param_1 + 9))
        ;
        return uVar3;
      }
      goto _L0;
    }
  }
  else {
    if (bVar1 == 2) {
      abStack_28[0] = 1;
      abStack_28[1] = 2;
      abStack_28[2] = 4;
      abStack_28[3] = 5;
      bVar1 = abStack_28[(*(byte *)(param_1 + 10) & 1) + (*(uint *)(puVar4 + 8) >> 0xc & 1) * 2];
      if (bVar1 != 0) goto _L0;
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0xe2,
                  "nwk_do_attach",&_LC1);
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0xf0,
                  "nwk_do_attach",
                  "(nwk_address_update(nwk_get_extended_address(), nwk_get_short_address(), &(nwk_addr_ref_t){0})) == 0"
                 );
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0xf7,
                  "nwk_do_attach",
                  "(nwk_mm_set_pib_attr(best_parent->mac_iface_idx, 0x61U, &channel)) == 0");
  }
  if ((byte)(bVar1 - 4) < 2) {
    uVar3 = nwk_send_network_comm_req
                      (puVar4,1,*(byte *)(param_1 + 10) & 1,*(undefined1 *)(param_1 + 9));
    return uVar3;
  }
_L0:
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x121,
                "nwk_do_attach",&_LC1);
  return 0x2c3;
}

